#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define abs(a) ((a<0) ? -a : a)
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);

const int N = (int)2e5 + 9;
int req_pos[N];
int cnt[N];

int main(){
    fastIO;
    int n;
    cin >> n;
    int sk;
    for(int i = 1;i<=n;i++){
        cin >> sk;
        req_pos[sk]=i;
    }
    char l;
    for(int i = 1;i<n;i++){
        cin >> l;
        cnt[i]=(l=='0');
        cnt[i]+=cnt[i-1];
    }
    cnt[n]=cnt[n-1];
    int lef,rig;
    for(int i = 1;i<=n;i++){
        //it should be at i-th pos
        lef = i;
        rig = req_pos[i];
        if(rig<lef)swap(lef,rig);
        if(lef==rig)continue;
        if(cnt[rig-1]-cnt[lef-1]>0){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}