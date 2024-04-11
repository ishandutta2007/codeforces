#include <bits/stdc++.h>
using namespace std;
char tab[100][100][100];
int ojc[100], odw[100];
pair<int, int> pom[1002];
int kra[102][102];
void dfs(int n)
{
    odw[n]=1;
    for (int i=1; i<=9; i++)
    {
        if (odw[i]==0 && kra[n][i]==1)
            dfs(i);
    }
}
bool is_path(int v, int w)
{
    for (int i=0; i<10; i++)
        odw[i]=0;
    dfs(v);
    return odw[w]==1;
}
void init()
{
    int akt=4;
    for (int i=1; i<=9; i++)
    {
        for (int j=i+1; j<=9; j++)
        {
            //cout << akt << " " << j << " " << i << "\n";
            pom[akt]={j-1, i-1};
            akt+=2;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    int n;
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            cin >> kra[i][j];
        }
    }
    vector<int> sss;
    for (int i=1; i<=n; i++)
    {
        if (ojc[i]!=0)
          continue;
        ojc[i]=i;
        sss.push_back(i);
        for (int j=i+1; j<=n; j++)
        {
            if (is_path(i, j) && is_path(j, i))
                ojc[j]=i;
        }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (kra[i][j]==1)
            {
                kra[ojc[i]][ojc[j]]=1;
            }
        }
    }
    do
    {
        int czy=1;
        for (int i=0; i<sss.size(); i++)
        {
            for (int j=i+1; j<sss.size(); j++)
            {
                if (kra[sss[j]][sss[i]]==1)
                    czy=0;
            }
        }
        if (czy==1)
            break;
        next_permutation(sss.begin(), sss.end());
    } while (true);
    for (int i=0; i<75; i++)
    {
        tab[0][i][0]='.';
        tab[0][i][1]='.';
        tab[0][i][2]='.';
        tab[1][i][0]='.';
        tab[1][i][1]='.';
        tab[1][i][2]='.';
    }
    int akt=2;
    for (int ii=sss.size()-1; ii>=0; ii--)
    {
        ///warstwa 'pelna'
        for (int j=0; j<9; j++)
        {
            tab[akt][j%3][j/3]='#';
        }
        for (int i=3; i<75; i++)
        {
            tab[akt][i][0]='#';
            if (i%2==1)
            {
                tab[akt][i][1]='.';
                tab[akt][i][2]='.';
            }
            else
            {
                tab[akt][i][1]='#';
                tab[akt][i][2]='.';
                if (pom[i].first == ii && kra[sss[pom[i].second]][sss[pom[i].first]] == 1)
                    tab[akt][i][2]='#';
            }
        }
        akt++;
        ///warstwa 'pusta'
        for (int j=0; j<9; j++)
        {
            if (ojc[j+1]==sss[ii])
                tab[akt][j%3][j/3]='0'+j+1;
              else
                tab[akt][j%3][j/3]='.';
        }
        for (int i=3; i<75; i++)
        {
            tab[akt][i][0]='.';
            tab[akt][i][2]='.';
            if (i%2==1)
            {
                tab[akt][i][1]='.';
            }
            else
            {
                tab[akt][i][1]='#';
                if ((pom[i].second == ii || pom[i].first == ii) && pom[i].first < sss.size() && kra[sss[pom[i].second]][sss[pom[i].first]] == 1)
                    tab[akt][i][1]='.';
            }
        }
        akt++;
    }
    for (int i=0; i<75; i++)
    {
        tab[akt][i][0]='#';
        tab[akt][i][1]='#';
        tab[akt][i][2]='#';
    }
    akt++;
    for (akt; akt<30; akt++)
    {
        for (int i=0; i<75; i++)
        {
            tab[akt][i][0]='.';
            tab[akt][i][1]='.';
            tab[akt][i][2]='.';
        }
    }
    cout << "75 3 30\n";
    for (int h=29; h>=0; h--)
    {
        for (int j=0; j<3; j++)
        {
            for (int i=0; i<75; i++)
            {
                cout << tab[h][i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    } 
}