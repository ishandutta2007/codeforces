#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

int main(){
    fastIO;
    int n;
    cin >> n;
    int pos[n];
    char k;
    cin >> k;
    int x = 0,y = 0;
    if(k=='U')
        y++;
    else
        x++;
    if(y==0)
        pos[0]=1;//right
    else
        pos[0]=0;//left
        int ans = 0;
    for(int i = 1;i<n;i++){
        cin >> k;
        if(k=='U')
            y++;
        else
            x++;
        if(x==y)
            pos[i]=pos[i-1];
        else if(x>y)
            pos[i]=1;
        else
            pos[i]=0;
        if(pos[i]!=pos[i-1])ans++;
    }
    cout << ans;
    return 0;
}