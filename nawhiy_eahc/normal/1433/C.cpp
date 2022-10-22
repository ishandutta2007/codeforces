#include <iostream>
using namespace std;

int dominant(){
    int n, m=0, result;
    bool b=true;
    cin >> n;
    int a[300002];
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]>m) m=a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=m) b=false;
    }
    for(int i=1;i<n;i++){
        if(a[i+1]==m && a[i]!=m){
            result=i+1;
            break;
        }
        if(a[i]==m && a[i+1]!=m){
            result=i;
            break;
        }
    }
    if(b) return -1;
    else return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    for(int i=1;i<=t;i++){
        cout << dominant() << endl;
    }
    
    return 0;
}