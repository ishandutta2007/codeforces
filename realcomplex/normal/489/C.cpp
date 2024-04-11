#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main()
{
    int n,s;
    cin >> n >> s;
    if(s == 0 && n == 1){
        cout << 0 << " " << 0;
    }
    else if(s == 0 || n*9 < s){
        cout << -1 << " " << -1;
    }
    else{
        int mx[n],mn[n];
        mx[0] = 1;
        mn[0] = 1;
        for(int i = 1;i<n;i++){
            mx[i] = 0;
            mn[i] = 0;
        }
        int rez = s;
        int el = 0;
        while(rez > 1){
            while(mx[el] < 9 && rez>1){
                mx[el]++;
                rez--;
            }
            el++;
        }
        rez = s;
        el = n-1;
        while(rez > 1){
            while(mn[el] < 9 && rez>1){
                mn[el]++;
                rez--;
            }
            el--;
        }
        for(int i = 0;i<n;i++){
            cout << mn[i];
        }
        cout << " ";
        for(int i = 0;i<n;i++){
            cout << mx[i];
        }
    }
    return 0;
}