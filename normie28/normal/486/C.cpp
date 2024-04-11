#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
ll ff=-1,fs,sf=-1,ss;
ll inv[100005];
ll done[100005];
int main()
{  
    ll n,p,count=0,temp,res=0,val,temp1,temp2,temp3,temp4,temp5,temp6;
    cin>>n>>p;
    p--;
    string a;
    cin>>a;
    for(int i=0;i<n;i++)
        if(a[i]!=a[n-1-i])
        {
            inv[i]=1;
            res+=min(abs(a[i]-a[n-i-1]),abs(26-abs(a[i]-a[n-1-i])));
            if(i<n/2)
            {
                fs=i;
                if(ff==-1) ff=i;
            }
            if(i>=n/2)
            {
                ss=i;
                if(sf==-1) sf=i;
            }
        }
    if(n%2==1)
        inv[n/2]=0;
        temp1=temp2=temp3=temp4=temp5=temp6=1e18;
  
  if(p>=n/2)
  {
                temp1=0;
                temp1+=n-p;
                val=-1;    
                for(int i=n-1-p;i<=n/2;i++)
                    if(inv[i]==1) {val=i;}
                temp1+=val+1;
          
                temp2=0;
                val=p;
                for(int i=p;i>=n/2;i--)
                    if(inv[i]==1) val=i;
                ll val2=val;    
                temp2+=p-val;
                for(int i=n-1-p-1;i>=0;i--)
                    if(inv[i]==1) val=i;
                    
                temp2+=val2-val;
                if(sf<=p&&p<=ss)
                    temp5=2*min(ss-p,p-sf)+max(ss-p,p-sf);
                else if(ss<=p)
                    temp5=p-sf;
                else if(p<=sf)
                    temp5=ss-p;
  }
  else
  {
          
                temp3=0;
                val=p;
                for(int i=p;i<=n/2;i++)
                    if(inv[i]==1&&done[i]==0) {val=i;done[i]=done[n-i-1]=1;}
                temp3+=val-p;    
                ll val2=val;
                for(int i=n-p;i<n;i++)
                    if(inv[i]==1) val=i;
                temp3+=val-val2; 
                temp4=0;
                temp4+=p;
                val=n;
                for(int i=n-1-p;i>=n/2;i--)
                    if(inv[i]==1) val=i;
                temp4+=n-val;   
                if(ff<=p&&p<=fs)
                    temp6=2*min(fs-p,p-ff)+max(fs-p,p-ff);
                else if(fs<=p)
                    temp6=p-ff;
                else if(ff>=p)
                    temp6=fs-p;
  }     
    count=1e18;
    count=min(count,temp1);
    count=min(count,temp3);
    count=min(count,temp4); 
    count=min(count,temp2);
    count=min(count,temp5);
    count=min(count,temp6);         
    if(count==1e18) count=0;
    count+=res/2;
    if(ff==-1) cout<<"0"<<endl;
    else cout<<count<<endl;
    return 0;
}