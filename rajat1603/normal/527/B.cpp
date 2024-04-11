#include<bits/stdc++.h>
using namespace std;
inline int scan(){
    char c = getchar();
    int x = 0;
    while(c<'0'||c>'9'){
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar();
    }
    return x;
}
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define author rajat1603
#define N 200002
#define inf 2147483646
int main(){
    int n; cin>>n;
    char a[N],b[N];cin>>a>>b;
    int val1=0, val2=0, ans=0;
    int arr[39][39]={0};
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            if(arr[b[i]-'a'][a[i]-'a']){
                val1=i+1;
                val2=arr[b[i]-'a'][a[i]-'a'];
                break;
            }
            arr[a[i]-'a'][b[i]-'a']=i+1;
        }        
    }
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            ans++;
        }
    }
    int f=0;
    if(val1==0){
        int x[28]={0};
        int y[28]={0};
        for(int i=0; i<n; i++){
            if(a[i]!=b[i]){
                if(y[a[i]-'a']){
                    val1=y[a[i]-'a'];
                    val2=i+1;
                    break;
                }
                else if(x[b[i]-'a']){
                    val1=x[b[i]-'a'];
                    val2=i+1;
                    break;
                }
                x[a[i]-'a']=i+1;
                y[b[i]-'a']=i+1;
            }
        }
        if(val1) f=1;
    }
    if(val1!=0&&ans){
        cout<<ans-2+f<<endl;
        cout<<val1<<" "<<val2<<endl;
    }
    else cout<<ans<<"\n-1 -1";
}