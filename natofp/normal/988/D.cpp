#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{


    vector <int> odpowiedz;
    int n;
    cin>>n;
    set<long long int> a;
    for(int i=0;i<n;i++)
    {
        long long int x;
        cin>>x;
        a.insert(x);

    }
    int ilosc=1;
    odpowiedz={*a.begin()};
    for(int d=1;d<=(1<<30);d*=2)
    {
        for(auto s :a)
        {
            if(a.count(s+d))
            {
                if(ilosc<2)
                {
                    ilosc=2;
                    odpowiedz={s,s+d};

                }
                if(a.count(s+2*d))
                {
                    ilosc=3;
                    odpowiedz={s,s+d,s+2*d};
                }
            }
        }
        if(d==1<<30) break;
    }
    cout<<ilosc<<endl;
    for(auto s: odpowiedz)
        cout<<s<<" ";
    return 0;
}