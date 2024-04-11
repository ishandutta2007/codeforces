#include <bits/stdc++.h>
using namespace std;
int knights[100000];
 

vector<int> div(int X){
    vector<int> ret;
    for(int d = 2; d * d <= X; d++){
        if(X % d == 0){
            ret.push_back(d);
            if(d * d != X) ret.push_back(X / d);
        }
    }
    ret.push_back(X);
    sort(ret.begin(), ret.end());
    return ret;
}
 
int main(){
 

    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &knights[i]);
    

    vector<int> divisors = div(N);
    int l = divisors.size();


    bool ok = false;
    for(auto &p : divisors){
        if(p == 2) continue;
        int parcel = N / p;
        for(int i = 0; i < parcel; i++){
            int count = 1;
            if(knights[i] == 1){
                for(int j = 1; j < p; j++) if(knights[i + j * parcel] == 1) count++;
            }

            if(count == p){
                ok = true;
                break;
            }
        }
    }
    
    // 4. .
    if(ok) printf("%s\n", "YES");
    else   printf("%s\n", "NO");
    return 0;
 
}