#include <iostream>

using namespace std;

int main()
{
    int n;
    int tab[2];
    cin>>n>>tab[0]>>tab[1];
    char * wyraz;
    wyraz=new char[n];
    for(int i=0;i<n;i++)
    {
        cin>>wyraz[i];
    }




    int suma=tab[0]+tab[1];

         if(wyraz[0]=='.')
    {
        if(tab[0]>0 || tab[1]>0)
        {
            if (tab[1]>tab[0])
                {
                    tab[1]--;
                    wyraz[0]='b';
                }
                else{
                    tab[0]--;
                    wyraz[0]='a';
                }
        }
    }
    {
        for(int i=1;i<n;i++)
        {
            if(wyraz[i]=='.' && wyraz[i-1]=='a' && tab[1]>0) {wyraz[i]='b'; tab[1]--;}
            else if(wyraz[i]=='.' && wyraz[i-1]=='b' && tab[0]>0) {wyraz[i]='a'; tab[0]--;}
            else if (wyraz[i]=='.' && wyraz[i-1]!='a' && wyraz[i-1]!='b')
            {
                if(tab[0]>0 || tab[1]>0)
            {
                if (tab[1]>tab[0])
                {
                    tab[1]--;
                    wyraz[i]='b';
                }
                else{
                    tab[0]--;
                    wyraz[i]='a';
                }
            }
            }

        }
    }

    delete [] wyraz;
    cout<<suma-tab[1]-tab[0];

}