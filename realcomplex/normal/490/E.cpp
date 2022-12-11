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

string ava(string cur,string las){
    if(cur.size() > las.size()){
        if(cur[0] == '?') cur[0] = '1';
        for(int i = 0;i<cur.size();i++) if(cur[i] == '?') cur[i] = '0';
        return cur;
    }
    else if(cur.size() < las.size()){
        cout << "NO";
        exit(0);
    }
    else{
        string ans = "99999999999999";
        string tek;
        for(int j = 0;j<cur.size();j++){
            tek = cur;
            if(cur[j] == '?'){
                cur[j] = las[j];
                if(las[j] == '9'){
                    tek[j] = '9';
                }
                else{
                    tek[j] = las[j]+1;
                }
            }
            for(int i = j+1;i<cur.size();i++){
                if(tek[i] == '?') tek[i] = '0';
            }
            if(tek > las){
                if(tek<ans){
                    ans = tek;
                }
            }
        }
        if(ans == "99999999999999"){
            cout << "NO";
            exit(0);
        }
        return ans;
    }
}

int main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    string k[n+1];
    for(int j = 1;j<=n;j++){
        cin >> k[j];
        k[j] = ava(k[j],k[j-1]);
    }
    cout << "YES\n";
    for(int i = 1;i<=n;i++)cout << k[i] << "\n";
    return 0;
}