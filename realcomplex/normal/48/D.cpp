#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e18

void open(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int perm[100005];

int main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    pair<int,int>sk[n];
    for(int j = 0;j<n;j++){
        cin >> sk[j].fi;
        sk[j].se = j;
    }
    sort(sk,sk+n);
    int rez[n];
    int l = 1;
    int an = 0;
    for(int j = 0;j<n;j++){
        if(sk[j].fi != l){
            cout << -1;
            exit(0);
        }
        int cnt = 1;
        while(sk[j].fi == l){
            if(sk[j].fi-perm[cnt]!=1){
                cout << -1;
                exit(0);
            }
            rez[sk[j].se] = cnt;
            perm[cnt] = l;
            an = max(an,cnt);
            cnt++;
            j++;
        }
        j--;
        l++;
    }
    cout << an << "\n";
    for(int j = 0;j<n;j++) cout << rez[j] << " ";
    return 0;
}