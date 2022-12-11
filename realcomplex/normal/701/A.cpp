#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define f first
#define s second
#define t abs

int main(){

    int n;
    cin >> n;
    vector<pair<int,int> >c(n);
    for(int i = 0;i<n;i++){
        cin >> c[i].f;
        c[i].s = i;
    }
    sort(c.begin(),c.end());
    int sp = n-1;
    for(int x = 0;x<n/2;x++){
        cout << c[x].s+1 << " " << c[sp].s+1 << "\n";
        sp--;
    }
    return 0;
}