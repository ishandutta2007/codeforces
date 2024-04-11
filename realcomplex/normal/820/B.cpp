#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

int main(){
    ld n,a;
    cin >> n >> a;
    ld base = 180/n;
    ld current_angle;
    ld diffr = 1000000.0;
    int indx=n;
    int ans = 3;
    for(ld i = 0;i<n-2;i++){
        current_angle=base+(base*i);
        if(abs(current_angle-a)<diffr){
            diffr=abs(current_angle-a);
            ans=indx;
        }
        indx--;
    }
    cout << "1 2 " << ans << "\n";
    return 0;
}