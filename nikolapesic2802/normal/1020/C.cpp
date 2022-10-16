#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%i %i",&n,&m);
    int broj_prve=0;
    vector<pair<int,multiset<int> > > setovi(m+2);
    multiset<int> svi;
    long long cena=0;
    long long minn=-1;
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        if(a==1)
        {
            broj_prve++;
        }
        else
        {
            setovi[a].second.insert(b);
            //printf("Dodajem %i u %i\n",b,a);
            setovi[a].first++;
            svi.insert(b);
        }
    }
    /*for(int i=0;i<setovi.size();i++)
    {
        printf("Set %i:\n",i);
        printf("Broj clanova:%i\n",setovi[i].first);
        multiset<int>::iterator it=setovi[i].second.begin();
        for(int j=0;j<setovi[i].first;j++)
        {
            printf("%i\n",*it);
            it++;
        }
    }*/
    while(true)
    {
        //printf("Usao!\n");
        sort(setovi.begin(),setovi.end());
        //printf("%i %i\n",setovi[3].first,setovi[6].first);
        int maxx=setovi[setovi.size()-1].first;
        //printf("Maxx:%i, broj:%i\n",maxx,broj_prve);
        if(broj_prve>maxx)
        {
            if(minn==-1)
            {
                printf("0\n");
                return 0;
            }
            printf("%I64d\n",min(minn,cena));
            return 0;
        }
        int razlika=maxx-broj_prve+1;
        multiset<int>::iterator it;
        long long tr=0;
        it=svi.begin();
        for(int i=0;i<razlika;i++)
        {
            int lol=*it;
            it++;
            tr+=(long long) lol;
        }
        //printf("Ako uzmem najjeftinije:%I64d\n",tr);
        if(minn>cena+tr||minn==-1)
        {
            minn=cena+tr;
        }
        int tren=setovi.size()-1;
        while(setovi[tren].first==maxx)
        {
            //printf("Wtf\n");
            broj_prve++;
            setovi[tren].first=setovi[tren].first-1;
            cena+=(long long)(*setovi[tren].second.begin());
            //printf("Cena: %lld\n",cena);
            svi.erase(svi.find(*setovi[tren].second.begin()));
            setovi[tren].second.erase(setovi[tren].second.begin());
            tren--;
        }
    }
    return 0;
}