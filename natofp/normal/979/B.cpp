#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    int index;
    int n;
    cin>>n;
    string wyrazy[3];
    cin>>wyrazy[0]>>wyrazy[1]>>wyrazy[2];
    int x=0;
    int wyniki[3]={0,0,0};
    int tab[256];
    for(int j=0;j<3;j++)
    {
        x=0;
        for(int i=0;i<256;i++)
        tab[i]=0;
    for(int i=0;i<wyrazy[j].length();i++)
    {
        tab[wyrazy[j][i]]++;
    }
    for(int i=0;i<256;i++)
        if(x<tab[i]) x=tab[i];
    wyniki[j]=x;
    }
    int odp[3]={0,0,0};

    for(int i=0;i<3;i++)
        odp[i]=wyniki[i]+n;
    if(n!=1)
    {

    for(int i =0;i<3;i++)
        if(odp[i]>wyrazy[i].length()) odp[i]=wyrazy[i].length();
    }
    else{
            for(int i=0;i<3;i++)
        if(odp[i]>wyrazy[i].length()) odp[i]-=2;
    }



    int naj=odp[0]; index=0;
    for(int i=1;i<3;i++)
        if(odp[i]>naj) {naj=odp[i]; index=i;}
    sort(odp,odp+3);
    if(odp[2]==odp[1]) cout<<"Draw";
    else
        {
            if(index==0) cout<<"Kuro";
            else if(index==1) cout<<"Shiro";
            else cout<<"Katie";


        }



    return 0;
}