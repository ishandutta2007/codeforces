#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e18

void open(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
}

int main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    m+=2;
    int lef[n],rig[n];
    int k = 0;
    char l;
    for(int j = n-1;j>=0;j--){
        lef[j] = m;
        rig[j] = 1;
        for(int i = 1;i<=m;i++){
            cin >> l;
            if(l == '1'){
                lef[j] = min(lef[j],i);
                rig[j] = max(rig[j],i);
                k = max(k,j);
            }
        }
    }
    int ans = 1e9;
    int tek;
    int t;
    int bit = 0;
    for(int j = 0;j<(1<<k);j++){
        tek = 0;
        t = 0;
        for(int i = 0;i<k;i++){
            if(j&(1<<i)){
                if(t == 0){
                    tek += m-1;
                }
                else{
                    tek += (m-lef[i])*2;
                }
                t = 1;
            }
            else{
                if(t == 1){
                    tek += m-1;
                }
                else{
                    tek += (rig[i]-1)*2;
                }
                t = 0;
            }
        }
        tek += k;
        if(t==0){
            tek += rig[k]-1;
        }
        else{
            tek += m-lef[k];
        }
        if(ans > tek){
            bit = j;
            ans = tek;
        }
    }
    cout << ans;
    return 0;
}