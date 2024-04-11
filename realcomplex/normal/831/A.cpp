#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair

int main() {

    int n;
    cin >> n;
    int sk[n];
    int st = 0;
    for(int i = 0;i<n;i++){
        cin >> sk[i];
    }
    bool is = true;
    for(int x = 1;x<n;x++){
        if(st == 0){
            if(sk[x] <= sk[x-1]){
                st = 1;
            }
        }
        if(st == 1){
            if(sk[x] != sk[x-1]){
                st = 2;
            }
        }
        if(st == 2){
            if(sk[x] >= sk[x-1]){
                is = false;
            }
        }
    }
    if(is == false){
        cout << "NO";
    }
    else{
        cout << "YES";
    }
	return 0;
}