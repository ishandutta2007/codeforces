#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int moves(string a,string b){
    int m = 0;
    if(a == b){
        return 0;
    }
    for(int i = 0;i<a.size();i++){
        a += a[0];
        a.erase(0,1);
        m++;
        if(a == b){
            return m;
        }
    }

    return -1;
}

int main() {

    int n;
    cin >> n;
    string v[n];
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    int sum = 0;
    int tmoves = 10000000;
    int cm = 0;
    for(int i = 0;i<n;i++){
        cm = 0;
        for(int x = 0;x<n;x++){
            if(i != x){
                if(moves(v[x],v[i]) != -1){
                    cm += moves(v[x],v[i]);
                }
                else{
                    cm = -1;
                    break;
                }
            }
        }
        if(cm < tmoves && cm != -1){
            tmoves = cm;
        }
    }
    if(tmoves == 10000000){
        cout << -1;
    }
    else{
        cout << tmoves;
    }
	return 0;
}