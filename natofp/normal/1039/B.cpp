#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int l=1;
long long int r=1e18;


void BS(long long int k,long long int n)
{
    while(r-l>80)
    {
        
        long long int mid = (l+r)/2;
        cout<<l<<" "<<mid<<endl; fflush(stdout);
        string s; cin>>s;
        if(s=="Yes") r=mid;
        else if(s=="Bad") exit(0);
        else l=mid+1;
        l-=k; r+=k;
        l=max(1LL,l); r=min(r,n);
    }
}

bool zgadnij(long long a)
{
    cout<<a<<" "<<a<<endl; fflush(stdout);
    string s; cin>>s;
    if(s=="Yes") exit(0);
    else if(s=="Bad") exit(0);
    else return false;
}

int main()
{
    int i;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand( time( NULL ) );
    long long int n;
    long long int k;
    cin>>n>>k;
    r=n;
    i=1;
    while(i<4500)
    {

        BS(k,n);
        if(r-l<=80)
        {

            i++;
            
           
            
                 int c=rand()%(r-l+1);
                   zgadnij(l+c);
                   l-=k; r+=k;
                   l=max(1LL,l); r=min(r,n);
            


        }
         
    }


    return 0;
}