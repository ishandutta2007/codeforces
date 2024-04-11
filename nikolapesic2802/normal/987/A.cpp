#include <bits/stdc++.h>

using namespace std;
bool visited[7];
string niz[7]= { "purple",
                 "green",
                 "blue",
                 "orange",
                 "red",
                 "yellow"
               };
string niz2[7]= { "Power",
                 "Time",
                 "Space",
                 "Soul",
                 "Reality",
                 "Mind"
               };
void dodaj(string n)
{
    for(int i=0;i<6;i++)
    {
        if(n==niz[i])
        {
            visited[i]=true;
        }
    }
}
void pisi()
{
    int cnt=0;
    for(int i=0;i<6;i++)
    {
        if(!visited[i])
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    for(int i=0;i<6;i++)
    {
        if(!visited[i])
        {
            cout<<niz2[i]<<endl;
        }
    }
}
int main()
{
    int n;
    scanf("%i",&n);
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        dodaj(s);
    }
    pisi();
    return 0;
}