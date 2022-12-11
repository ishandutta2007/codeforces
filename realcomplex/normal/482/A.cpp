#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e10
#define fi first
#define se second
#define mp make_pair

int main(){

    int n,k;
    cin >> n >> k;
    deque<int>el;
    for(int j = 1;j<=k+1;j++){
        el.push_back(j);
    }
    for(int i = 0;i<k+1;i++){
        if(i%2==0){
            cout << el.front() << " ";
            el.pop_front();
        }
        else{
            cout << el.back() << " ";
            el.pop_back();
        }
    }
    for(int j = k+2;j<=n;j++){
        cout << j << " ";
    }
    return 0;
}