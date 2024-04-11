#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int n;

pair<int, int> solve(pair<int, int> lr){
    int l, r;
    l = lr.first;
    r = lr.second;
    if(r - l == 1 || r - l == -n+1) return lr;

    cout << "? " << (l+r)/2 + 1 << endl;
    fflush(stdout);
    cin >> a[(l+r)/2];

    cout << "? " << (((l+r)/2 + n/2) % n) + 1 << endl;
    fflush(stdout);
    cin >> a[((l+r)/2 + n/2) % n];

    if(a[(l+r)/2] == a[((l+r)/2 + n/2) % n]){
        cout << "! " << (l+r)/2 + 1;
        return make_pair((l + r)/2, (l+r)/2);
    }

    if(a[(l+r)/2] > a[((l+r)/2 + n/2) % n]){
        return(solve(make_pair(l, (l+r)/2)));
    }

    if(a[(l+r)/2] < a[((l+r)/2 + n/2) % n]){
        return(solve(make_pair((l+r)/2, r)));
    }
}

int main(){

    pair<int, int> x;
    cin >> n;
    a.resize(n);

    if((n % 4) == 2){
        cout << "! " << -1;
        return 0;
    }

    cout << "? " << 1 << endl;
    fflush(stdout);
    cin >> a[0];

    cout << "? " << n/2 + 1 << endl;
    fflush(stdout);
    cin >> a[n/2];

    cout << "? " << n/4 + 1 << endl;
    fflush(stdout);
    cin >> a[n / 4];

    cout << "? " << 3*(n/4) + 1 << endl;
    fflush(stdout);
    cin >> a[3*(n/4)];


    if(a[0] == a[n/2]){
        cout << "! " << 1;
        return 0;
    }

    else if(a[n/4] == a[3*(n/4)]){
        cout << "! " << n/4 + 1;
        return 0;
    }

    else if(a[0] < a[n/2] && a[3*(n/4)] > a[n/4]){
        x = solve(make_pair(n/4, n/2));
        return 0;
    }


    else if(a[0] > a[n/2] && a[3*(n/4)] > a[n/4]){
        x = solve(make_pair(n/2, 3*(n/4)));
        return 0;
    }

    else if(a[0] < a[n/2] && a[3*(n/4)] < a[n/4]){
        x = solve(make_pair(0, n/4));
        return 0;
    }

    else if(a[0] > a[n/2] && a[3*(n/4)] < a[n/4]){
        x = solve(make_pair(3*(n/4), n));
        return 0;
    }
}