#include <iostream>
#include <string>
#define inf (1 << 14)
using namespace std;
bool block[50][50];
int n;
int main(){
    cin >> n;
    int cnt[3];
    cnt[1] = cnt[2] = 0;
    for(int i=0;i<n;i++){
        int v;
        cin >> v;
        cnt[v]++;
    }
    if(cnt[1] == 0 || cnt[2] == 0){
        for(int i=0;i<n;i++){
            cout << (cnt[1] ? 1 : 2) << ' ';
        }
    }else{
        cout << "2 1 ";
        cnt[2]--; cnt[1]--;
        while(cnt[2]){
            cout << 2 << ' ';
            cnt[2]--;
        }
        while(cnt[1]){
            cout << 1 << ' ';
            cnt[1]--;
        }
    }
    return 0;
}