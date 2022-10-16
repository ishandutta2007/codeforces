#include <iostream>

using namespace std;

long long int licznik=0;

void Merge(int a[],int p,int q,int r)
{
    int * L;
    int * R;
    L=new int[q-p+2];
    R=new int[r-q+1];
    for(int i=p;i<=q;i++)
        {L[i-p]=a[i];}
    for(int i=q+1;i<=r;i++)
        {R[i-q-1]=a[i];}
    L[q-p+1]=2000000000;
    R[r-q]=2000000000;

    int x=0;
    int y=0;
    for(int i=p;i<=r;i++)
    {
        if(L[x]<=R[y])
        {

            a[i]=L[x];
            licznik+=y;

            x++;


        }
        else
        {

            a[i]=R[y];
            y++;

        }
    }

delete [] L;
delete [] R;
}

void Mergesort(int tab[],int p,int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
        Mergesort(tab,p,q);
        Mergesort(tab,q+1,r);;
        Merge(tab,p,q,r);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
cin.tie(0);
    int n;
    cin>>n;
    int * tab;
    tab=new int[n];
    for(int i=0;i<n;i++)
        cin>>tab[i];
    Mergesort(tab,0,n-1);
    if(n%2==0)
    {
        if(licznik%2==0) cout<<"Petr";
        else cout<<"Um_nik";
    }
    else
    {
        if(licznik%2==0) cout<<"Um_nik";
        else cout<<"Petr";
    }
}