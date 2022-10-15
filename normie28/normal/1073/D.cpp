    #include <bits/stdc++.h>
    #define pb push_back
    #define mp make_pair
    #define bekenes 31
    #define ss second
    #define ff first
    #define inf 5e8
    #define int long long
    #define endl '\n'
 
    using namespace std;
 
    void debug(int n, ...){
        va_list v1;
        va_start(v1,n);
        for(int i=0;i<n;i++){
            int val=va_arg(v1,int);
            printf("%d ",val);
        }
        va_end(v1);
        cout<<endl;
    }
 
    int arr[200005];
 
    int32_t main(){
        int n,t;
        cin>>n>>t;
        int minn=inf;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            minn=min(arr[i],minn);
        }
        int ans=0;
        while(t>=minn){
            int sum=0;
            int temps=t;
            int sayac=0;
            for(int i=0;i<n;i++){
                if(arr[i]<=temps){
                    temps-=arr[i];
                    sum+=arr[i];
                    sayac++;
                }
            }
            ans+=sayac*(t/sum);
            t%=sum;
        }
        cout<<ans;
    }