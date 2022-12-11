#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e9

void open(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
}

int cnt[2][2];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(abs(c-d)>1){
        cout << -1;
        exit(0);
    }
    string t[2];
    if(c==d){
        for(int j = 0;j<c;j++){
            t[0]+="47";
            t[1]+="74";
        }
        t[0]+="4";
        t[1]+="7";
    }
    else if(c<d){
        for(int j = 0;j<d;j++){
            t[0] += "74";
            t[1] += "74";
        }
    }
    else{
        for(int j = 0;j<c;j++){
            t[0] += "47";
            t[1] += "47";
        }
    }
    for(int i = 0;i<2;i++){
        for(int j = 0;j<t[i].size();j++){
            if(t[i][j] == '4') cnt[i][0]++;
            else cnt[i][1]++;
        }
    }
    if(cnt[0][0] <= a && cnt[0][1] <= b){
        a-=cnt[0][0];
        b-=cnt[0][1];
        int l,r;
        for(int j = 0;j<t[0].size();j++){
            if(t[0][j] == '4'){
                l = j;
                break;
            }
        }
        for(int j = t[0].size()-1;j>=0;j--){
            if(t[0][j] == '7'){
                r = j;
                break;
            }
        }
        for(int x = 0;x<t[0].size();x++){
            cout << t[0][x];
            if(x == l){
                for(int i = 0;i<a;i++){
                    cout << 4;
                }
            }
            if(x == r){
                for(int i = 0;i<b;i++){
                    cout << 7;
                }
            }
        }
    }
    else if(cnt[1][0] <= a && cnt[1][1] <= b){
        a-=cnt[1][0];
        b-=cnt[1][1];
        int l,r;
        for(int j = 0;j<t[1].size();j++){
            if(t[1][j] == '4'){
                l = j;
                break;
            }
        }
        for(int j = t[1].size()-1;j>=0;j--){
            if(t[1][j] == '7'){
                r = j;
                break;
            }
        }
        for(int x = 0;x<t[1].size();x++){
            cout << t[1][x];
            if(x == l){
                for(int i = 0;i<a;i++){
                    cout << 4;
                }
            }
            if(x == r){
                for(int i = 0;i<b;i++){
                    cout << 7;
                }
            }
        }
    }
    else{
        cout << -1;
    }
    return 0;
}