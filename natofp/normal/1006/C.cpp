#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=2e5+5;
vector<long long int> pre(nax,0);

long long int ile(int l,int r)
{
    if(l==0) return pre[r];
    return pre[r]-pre[l-1];
}

int main()
{
   int n; cin>>n;
   int * a=new int[n];
   for(int i=0;i<n;i++) cin>>a[i];
   pre[0]=a[0];
   for(int i=1;i<n;i++) pre[i]=pre[i-1]+a[i];
   long long int res=0;
   int wsk1=1;
   int wsk2=n-1;
   long long int poczatek=a[0];
   long long int suma=pre[n-1];
   while(wsk1<n)
   {
        while(wsk2>=0 && suma-ile(0,wsk2)<poczatek) wsk2--;
        if(poczatek==suma-ile(0,wsk2) && wsk1-1<=wsk2) res=max(res,poczatek);
        poczatek+=a[wsk1]; wsk1++;
        //if(wsk2<=wsk1) break;
        //cout<<wsk1<<" "<<wsk2<<endl;
   }
   cout<<res<<endl;
    return 0;
}