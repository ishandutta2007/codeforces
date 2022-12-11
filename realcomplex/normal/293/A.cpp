#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e18

void open(){
    freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}

int cnt[4];
/*
11
01
10
00
*/

int main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    char k[n*2];
    cin >> k;
    char t;
    for(int j = 0;j<n*2;j++){
        cin >> t;
        if(t == '1' && k[j] == '1'){
            cnt[0]++;
        }
        else if(t == '1' && k[j] == '0'){
            cnt[1]++;
        }
        else if(t == '0' && k[j] == '1'){
            cnt[2]++;
        }
        else{
            cnt[3]++;
        }
    }
    int q = 0;
    int p = 0,p1 = 0;
    for(int j = 0;j<n*2;j++){
        if(q == 0){
            if(cnt[0] > 0){
                p++;
                cnt[0]--;
            }
            else if(cnt[2] > 0){
                p++;
                cnt[2]--;
            }
            else if(cnt[1] > 0){
                cnt[1]--;
            }
            else{
                cnt[3]--;
            }
        }
        else{
            if(cnt[0] > 0){
                p1++;
                cnt[0]--;
            }
            else if(cnt[1] > 0){
                p1++;
                cnt[1]--;
            }
            else if(cnt[2] > 0){
                cnt[2]--;
            }
            else{
                cnt[3]--;
            }
        }
        q = 1-q;
    }
    if(p == p1) cout << "Draw";
    else if(p > p1) cout << "First";
    else cout << "Second";
    return 0;
}