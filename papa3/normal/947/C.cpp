#include<bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll

vector<int> v;

struct Node {
    Node *left, *right;
    int ile;
    Node() : ile( 0 ), left( nullptr ), right( nullptr ) {}
};

Node root;

void dodaj( int x ) {
    int a = 1<<30;
    Node *gdzie = &root;
    while( a ) {
        gdzie->ile++;
        if( gdzie->left == nullptr ) {
            gdzie->right = new Node;
            gdzie->left = new Node;
        }
        if( a&x ) {
            gdzie = gdzie->right;
        } else {
            gdzie = gdzie->left;
        }
        a/=2;
    }
    gdzie->ile++;
}

int znajdz( int x ) {
    int a = 1<<30;
    Node *gdzie = &root;
    int wy=0;
    while( a ) {
        gdzie->ile--;
        if( gdzie->left->ile == 0 ) {
            gdzie = gdzie->right;
            wy+=a;
        } else if( gdzie->right->ile == 0 ) {
            gdzie = gdzie->left;
        } else {
            if( a&x ) {
                gdzie = gdzie->right;
                wy+=a;
            } else {
                gdzie = gdzie->left;
            }
        }
        a/=2;
    }
    gdzie->ile--;
    return wy;
}

int32_t main() {
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );

    int n;
    cin >> n;
    for( int a, i=1; i<=n; i++ ) {
        cin >> a;
        v.push_back( a );
    }
    for( int a, i=1; i<=n; i++ ) {
        cin >> a;
        dodaj( a );
    }

    for( int i : v ) {
        int x = znajdz( i );
        //cout << x << ",";
        cout << (i^x) << " ";
    }

    return 0;
}