#include <iostream>

using namespace std;

bool T[1001];

int main()
{
    int p, q, l, r;
    cin>>p>>q>>l>>r;
    int a[p], b[p], c[q], d[q];
    for(int i=0; i<p; i++)
        cin>>a[i]>>b[i];
    for(int i=0; i<q; i++)
        cin>>c[i]>>d[i];
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<q; j++)
        {
            int tem1=a[i]-d[j];
            int tem2=b[i]-c[j];
            if(tem2<0)
                break;
            for(int k=tem1; k<=tem2; k++)
                if(k>=0)
                    T[k]=true;
        }
    }
    int res=0;
    for(int i=l; i<=r; i++)
        if(T[i])
            res++;
    cout<<res<<endl;
    return 0;
}