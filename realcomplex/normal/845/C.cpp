#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second

typedef long long ll;

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int> >sh;
    int a,b;
    for(int i = 0;i<n;i++){
        cin >> a >> b;
        sh.push_back(mp(a,1));
        sh.push_back(mp(b+1,-1));
    }
    sort(sh.begin(),sh.end());
    int j = 0;
    for(int y = 0;y<sh.size();y++){
        if(sh[y].se == 1){
            j++;
        }
        else{
            j--;
        }
        if(j > 2){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}