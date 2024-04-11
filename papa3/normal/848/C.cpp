#include<bits/stdc++.h>

using namespace std;

#define int long long

const int baza = 1<<17;

struct Node {
    struct punkt {
        punkt * left, * right;
        int val, key, pri, suma;
        punkt() : left( nullptr ), right( nullptr ), val( 0 ), key( 0 ), pri( rand() ), suma( 0 ) {}
        ~punkt() {
            if( left != nullptr ) delete left;
            if( right != nullptr ) delete right;
        }
    };

    punkt * korzen;
    Node() : korzen( nullptr ) {}

    punkt * attach( punkt * where, punkt * l, punkt * r ) {
        if( where == nullptr ) return nullptr;
        where->left = l;
        where->right = r;
        where->suma = where->val;
        if( l!=nullptr ) where->suma += l->suma;
        if( r!=nullptr ) where->suma += r->suma;
        return where;
    }

    punkt * merge( punkt * l, punkt * r ) {
        if( l==nullptr ) return r;
        if( r==nullptr ) return l;
        if( l->pri > r->pri ) return attach( l, l->left, merge( l->right, r ) );
        else return attach( r, merge( l, r->left ), r->right );
    }

    pair<punkt*, punkt*> split( punkt * what, int x ) {
        if( what==nullptr ) return {nullptr, nullptr};
        if( what->key == x ) {
            punkt * y = what->left;
            return {y, attach( what, nullptr, what->right )};
        }
        if( what->key < x ) {
            auto p = split( what->right, x );
            return {attach( what, what->left, p.first ), p.second};
        } else {
            auto p = split( what->left, x );
            return {p.first, attach( what, p.second, what->right)};
        }
    }

    int czytaj( int pyt_pocz ) {
        //cout << pyt_pocz << ": ";
        //debug( korzen );
        //cout << endl;
        auto p = split( korzen, pyt_pocz );
        int x=0;
        if( p.second != nullptr ) x = p.second->suma;
        korzen = merge( p.first, p.second );
        return x;
    }
    void add( int x, int ile ) {
        auto p = split( korzen, x );
        //debug( p.first ); cout << endl;
        //debug( p.second ); cout << endl;
        auto p2= split( p.second, x+1 );
        //debug( p2.first ); cout << endl;
        //debug( p2.second ); cout << endl;
        if( p2.first == nullptr ) {
            p2.first = new punkt;
            p2.first->key = x;
            //cout << "dodany ";
        }
        p2.first->val+=ile;
        p2.first->suma+=ile;
        /*if( p2.first->val == 0 ) {
            delete p2.first;
            p2.first = nullptr;
        }*/
        p.second = merge( p2.first, p2.second );
        korzen = merge( p.first, p.second );
    }

    void debug( punkt * where ) {
        if( where == nullptr ) return;
        cout << where->key << "," << where->val << "( ";
        debug( where->left );
        cout << ", ";
        debug( where->right );
        cout << " ) ";
    }
};

Node drz[baza*2];

void akt( pair<int, int> jak, int gdzie ) {
    gdzie += baza;
    //cout << jak.first << " " << jak.second << "\n";
    while( gdzie ) {
        //cout << gdzie << " ";
        //drz[gdzie].debug( drz[gdzie].korzen );
        //cout << endl;
        drz[gdzie].add( jak.first, jak.second );
        //cout << gdzie << " ";
        //drz[gdzie].debug( drz[gdzie].korzen );
        //cout << endl;
        gdzie/=2;
    }
}
int czytaj( int pyt_pocz, int pyt_kon, int pocz=0, int kon=baza, int gdzie=1 ) {
    if( pyt_kon <= pocz ) return 0;
    if( kon <= pyt_kon ) {
        //drz[gdzie].debug();
        //cout << endl;
        return drz[gdzie].czytaj( pyt_pocz );
    }
    int sr=(pocz+kon)/2;
    return  czytaj( pyt_pocz, pyt_kon, pocz, sr, gdzie*2 )+
            czytaj( pyt_pocz, pyt_kon, sr, kon, gdzie*2+1 );
}

set<int> pos[100010];
int tab[100010];
void remove( int gdzie ) {
    int id = tab[gdzie];
    auto it = pos[id].find( gdzie );
    if( it != pos[id].begin() && *it != *pos[id].rbegin() ) {
        int a = *(--it);
        it++;
        int b = *(++it);
        it--;
        akt( {a, b-a}, b );
    }
    if( it == pos[id].end() ) {
        cout << "bug" << endl;
    }
    if( it != pos[id].begin() ) {
        int a = *(--it);
        it++;
        akt( {a, a-gdzie}, gdzie );
    }
    it++;
    if( it != pos[id].end() ) {
        akt( {gdzie, gdzie-*it}, *it );
    }
    it--;
    pos[id].erase( it );
}
void add( int gdzie ) {
    int id = tab[gdzie];
    auto it = pos[ id ].insert( gdzie ).first;
    if( it != pos[id].begin() && *it != *pos[id].rbegin() ) {
        int a = *(--it);
        it++;
        int b = *(++it);
        it--;
        akt( {a, a-b}, b );
    }
    if( it != pos[id].begin() ) {
        int a = *(--it);
        it++;
        akt( {a, gdzie-a}, gdzie );
    }
    it++;
    if( it != pos[id].end() ) {
        akt( {gdzie, *it-gdzie}, *it );
    }
    it--;
}

main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( NULL );
    int n, m;
    cin >> n >> m;

    for( int i=1; i<=n; i++ ) {
        cin >> tab[i];
        add( i );
    }
    while( m-- ) {
        int a, b, c;
        cin >> a >> b >> c;
        if( a==2 ) {
            cout << czytaj( b, c+1 ) << "\n";
        } else {
            remove( b );
            tab[b] = c;
            add( b );
        }
    }
    return 0;
}
/*
5 5
4 1 3 1 2
1 5 3
1 4 4
2 1 2
2 2 5
1 5 4
*/



/*struct Node {
    Node * left, * right;
    int val;
    Node() : left( nullptr ), right( nullptr ), val( 0 ) {}
    ~Node() {
        if( left != nullptr ) {
            delete left;
            delete right;
        }
    }
    void add( int ile, int pyt, int pocz=0, int kon=baza ) {
        if( pocz+1 == kon ) {
            val+=ile;
            return;
        }
        zwal();
        int sr = (pocz+kon)/2;
        if( pyt < sr )
            left->add( ile, pyt, pocz, sr );
        else
            right->add( ile, pyt, sr, kon );
        val = left->val+right->val;
        if( val == 0 ) {
            delete left;
            delete right;
            left = right = nullptr;
        }
    }
    void zwal() {
        if( left==nullptr ) {
            left = new Node;
            right = new Node;
        }
    }
    int czytaj( int pyt, int pocz=0, int kon=baza ) {
        if( kon <= pyt ) return 0;
        if( pyt <= pocz ) return val;
        if( left==nullptr ) return 0;
        zwal();
        int sr = (pocz+kon)/2;
        return left->czytaj( pyt, pocz, sr )+right->czytaj( pyt, sr, kon );
    }
    void debug() {
        cout << val;
        if( left != nullptr ) {
            cout << "( ";
            left->debug();
            cout << " ";
            right->debug();
            cout << " )";
        }
    }
};*/