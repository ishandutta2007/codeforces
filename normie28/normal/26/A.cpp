

#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
 
int sopf(int n){
    set<int> d;
    for(int i=2; i*i <= n; i++){
        while(n % i == 0){
            n /= i;
            d.insert(i);
        }
    }
    if(n > 1)
        d.insert(n);
        
        
    return d.size();
}
 
 
int main(int argc, char* argv[]){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
       
    #ifdef _DEBUG
    freopen("input.txt","r",stdin);

    #endif
    
    int n; cin >> n;
    
    int d = 0;
    for(int i=1; i<=n; i++){
        if(sopf(i) == 2){
            //debug(i);
            d++;
        }
    }
    
    cout <<  d << "\n";
    
    return 0;
}