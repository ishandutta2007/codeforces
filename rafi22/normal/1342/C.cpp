#include <bits/stdc++.h>

using namespace std;

long long euklides(long long a, long long b)
{
    long long x=a,y=b;

	while(b)
		swap(a %= b, b);
	return x/a*y;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*int a=0;
    for(int i=1000;i<=9995;i++)
    {
        if(i%4%6==i%6%4) a++;
    }
    cout<<a<<endl;*/
   int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        long long a,b,q;
        cin>>a>>b>>q;
        long long nww=euklides(a,b);
        for(int j=0;j<q;j++)
        {
            long long r,l;
            cin>>l>>r;
            long long st,nd,ile;
            if(l%nww==0)
                st=l;
            else st=l-(l%nww)+nww;
            if(r%nww==0)
                nd=r;
            else nd=r-(r%nww);
            if(nd<l) ile=0;
            else ile=(nd-st)/nww+1;
            long long ans=ile*max(a,b);
            if(ile>0)
                ans-=max((long long)0,nd+(max(a,b)-1)-r);
            ans+=max((long long)0,min(r,(st-nww)+max(a,b)-1)-l+1);
            cout<<r-l+1-ans<<' ';
        }
        cout<<endl;
    }
    return 0;
}