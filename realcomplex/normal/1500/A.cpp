#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e6 + 10;
vector<int> id[N];
pii pip[N];
bool has[N];

int main(){
    fastIO;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ){
        cin >> a[i];
        id[a[i]].push_back(i+1);
    }
    int i1 = -1;
    for(int i = 0; i < N ; i ++ ){
        if(id[i].size() >= 4){
            cout << "YES\n";
            for(int j = 0 ; j < 4; j ++) {
                cout << id[i][j] << " ";
            }
            cout << "\n";
            return 0;
        }
        if(id[i].size() > 1){
            if(i1 != -1){
                cout << "YES\n";
                for(int q = 0; q < 2; q ++ ){
                    cout << id[i1][q] << " " << id[i][q] << " ";
                }
                cout << "\n";
                return 0;
            }
            i1 = i;
        }
    }
    if(i1 != -1){
        int cum = i1 * 2;
        for(int i = 0 ; i < cum; i ++ ){
            if(i == i1 || cum == i1) continue;
            if(!id[i].empty() && !id[cum - i].empty()){
                cout << "YES\n";
                cout << id[i][0] << " " << id[cum-i][0] << " " << id[i1][0] << " " << id[i1][1] << "\n";
                return 0;
            }
        }
    }
    for(int i = 0 ; i < N ; i ++ ){
        if(id[i].size() > 1)
            for(int j = 1; j < id[i].size(); j ++ ){
                a[id[i][j]-1] = -1;
            }
    }
    int cov;
    for(int i = 0 ; i < n; i ++ ){
        for(int j = i + 1; j < n; j ++ ){
            if(a[i] == -1 || a[j] == -1) continue;
            cov = a[i] + a[j];
            if(has[cov]){
                cout << "YES\n";
                cout << i + 1 << " " << j + 1 << " " << pip[cov].fi << " " << pip[cov].se << "\n";
                return 0;
            }
            pip[cov] = mp(i + 1, j + 1);
            has[cov]=true;
        }
    }
    cout << "NO\n";
    return 0;
}