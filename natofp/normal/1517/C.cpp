#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

const int nax = 505;
int a[nax][nax];
int kto[nax][nax];
int n;
int ans[nax][nax];

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i][i];
    for(int i=1;i<=n;i++) kto[i][i] = a[i][i];
    int xd = n;

    while(n >= 1){
        int down = xd - n;
        bool dbg = (n == 2);

        // propagacja :)
        bool met = false;
        for(int i=1;i<=n;i++){
            //if(dbg) cout<<"POLE"<<i<<" "<<i+down<<endl;
            if(a[i + down][i] == 1){
                //if(dbg) cout<<"CO"<<"WA"<<endl;
                // tego nie propagujemy
                met = true;
                continue;
            }
            else if(met == false){
                // w dol
                a[i + down + 1][i] = a[i + down][i] - 1;
                kto[i + down + 1][i] = kto[i + down][i];
                //if(dbg) cout<<"CO"<<i<<" "<<i+down+1<<endl;
            }
            else{
                //if(dbg) cout<<"CHUJ"<<endl;
                a[i + down][i - 1] = a[i + down][i] - 1;
                kto[i + down][i - 1] = kto[i + down][i];
            }
        }
        //cout<<"A"<<n<<endl;
        n--;
    }
    //cout<<"CO"<<endl;
    for(int i=1;i<=xd;i++){
        for(int j=1;j<=i;j++) cout<<kto[i][j]<<" ";
        cout<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
   // cin >> tt;
    while(tt--) solve();

    return 0;
}