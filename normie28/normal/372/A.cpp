
 #include <bits/stdc++.h>
using namespace std;
    
int main(){
    
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, c=0;
    int a[1000000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        
    }
    sort(a, a+n);
    
    
    int x=n/2, y=n-1;
    x--;
    while(x>=0&&y>=(n/2)){
        if (a[x]<=a[y]/2)
        {c++;
        
        x--;y--;    
        }
        else x--;
    }
    cout<<n-c;
           return 0;
    }