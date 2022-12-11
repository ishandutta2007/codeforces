#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define abs(a) ((a<0) ? -a : a)
#define pii pair<int,int>
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

int main(){
    int c,v0,v1,a,l;
    cin>>c>>v0>>v1>>a>>l;
    c-=v0;
    int i = 1;
    int red;
    while(c>0){
        red=min(v1,v0+(a*i));
        c-=red;
        c+=l;
        ++i;
    }
    cout << i;
    return 0;
}