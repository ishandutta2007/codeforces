#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

inline pair<int, int> rot( pair<int, int> p, int jak ) {
    if( jak == 0 ) {
        return {p.first, p.second};
    }
    return rot( {-p.second, p.first}, jak-1 );
}

vector<pair<int, bool> >          xxxxx[800000];
vector<pair<int, bool> > * tab = &xxxxx[400000];

pair<pair<int, int>, bool> pppp[2000010];
pair<pair<int, int>, bool> * punkt = &pppp[1000000];

vector<pair<int, int> > v;

void zrob( int jak ) {
    if( v.size()==0 ) return;
    pair<int, int> mi = rot( v[0], jak );
    for( pair<int, int> & i : v ) {
        i = rot( i, jak );
        if( punkt[ i.first+i.second ].second == false ) {
            punkt[ i.first+i.second ] = {i, true};
        } else if( i.second < punkt[ i.first+i.second ].first.second ) {
            punkt[ i.first+i.second ] = {i, true};
        }
        if( i.first+i.second < mi.first+mi.second ) mi=i;
        if( i.first+i.second == mi.first+mi.second && i.second < mi.second ) mi = i;
    }
    //cout << mi.first << " " << mi.second << "\n\n";
    pair<int, int> gdzie = {-300000, mi.first+mi.second+300000};
    pair<int, int> pom;
    bool kier;
    while( gdzie.first <= 300000 ) {
        pom = rot( gdzie, 4-jak );
        bool zm=0;
        if( punkt[ gdzie.first+gdzie.second ].second && punkt[ gdzie.first+gdzie.second ].first.second < gdzie.second ) {
            if( kier == 0 ) zm=1;
            kier=1;
        } else {
            if( kier == 1 ) zm=1;
            kier=0;
        }
        //if( gdzie.first > -10 && gdzie.first < 10 )
        //cout << jak << " " << pom.first << " " << pom.second << endl;
        if( jak==0 ) {
            tab[pom.first].push_back( {pom.second, 1} );
        } else if( jak==2 ) {
            tab[pom.first].push_back( {pom.second, 0} );
        } else if( jak==1 ) {
            if( zm==0 )
                tab[pom.first].push_back( {pom.second, !kier} );
        } else {
            if( zm==0 )
                tab[pom.first].push_back( {pom.second, kier} );
        }
        if( kier ) {
            gdzie.second--;
        } else {
            gdzie.second++;
        }
        gdzie.first++;
    }
    for( pair<int, int> & i : v ) {//zeruj tablice
        punkt[ i.first+i.second ] = {{0, 0}, 0};
        i = rot( i, 4-jak );
    }
}

int res=0;

void policz() {
    int pop=-100000;
    int ile=0;
    for( int i=-100000; i<=100000; i++ ) {
        sort( tab[i].begin(), tab[i].end() );
        ile = 0;
        pop = -100000;
        for( pair<int, bool> j : tab[i] ) {
            if( j.second ) {
                ile++;
                pop = j.first;
            } else {
                if( ile==3 )
                    res += max( (j.first-pop)/2, 0ll );
                ile--;
                pop = j.first;
            }
            //if( i>-5 && i<5 ) {
            //    cout << i << " " << ile << " " << pop << "\n";
            //}
        }
    }
}

void zeruj() {
    for( int i=-100000; i<=100000; i++ ) {
        tab[i].clear();
    }
}

void debug() {
    for( int i=-5; i<5; i++ ) {
        sort( tab[i].begin(), tab[i].end() );
        cout << i << "   ";
        for( pair<int, bool> j : tab[i] ) cout << j.first << "," << j.second << " ";
        cout << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    //cout << rot( {-2, -1}, 1 ).first << " " << rot( {-2, -1}, 1 ).second;
    //cout << rot( {1, -2}, 3 ).first << " " << rot( {1, -2}, 3 ).second;
    //return 0;

    vector<pair<int, int> > points;
    int n;
    cin >> n;
    for( int a, b, i=0; i<n; i++ ) {
        cin >> a >> b;
        if( (a+b)%2 ) points.push_back( {a, b} );
        else v.push_back( {a, b} );
    }

    for( int i=0; i<4; i++ ) {
        zrob( i );
    }
    policz();
    //debug();
    //cout << res << endl;
    zeruj();
    swap( points, v );
    for( int i=0; i<4; i++ ) {
        zrob( i );
    }
    policz();
    //debug();
    cout << res;

    return 0;
}