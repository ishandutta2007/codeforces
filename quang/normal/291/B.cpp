#include <bits/stdc++.h>
#define filein freopen("inp.txt", "r", stdin)
#define fileout freopen("out.txt", "w", stdout)
#define EXTREMELY
#define LIMIT 100010

using namespace std;

string s, ss;
int vt[LIMIT], d = 0;
int opened;

void xuli(string ss)
{
    ss = ' ' + ss + ' ';
    string sss = "";
    for(int i = 1; i < (int)ss.size(); i++)
    {
        if(ss[i] != 32) sss += ss[i];
        else
        if(ss[i - 1] != 32)
        {
            cout << "<" << sss << ">" << endl;
            sss = "";
        }
    }
}

int main()
{
    //filein, fileout;
    getline(cin, s);
    for(int i = 0; i < (int)s.size(); i++) if(s[i] == '"') vt[++d] = i;
    if(!d)
    {
        xuli(s);
        return 0;
    }
    ss = s.substr(0, vt[1]);
    xuli(ss);
    for(int i = 1; i < d; i++)
    {
        ss = s.substr(vt[i] + 1, vt[i + 1] - vt[i] - 1);
        if(i % 2) cout << "<" << ss << ">" << endl;
        else
            xuli(ss);
    }
    ss = s.substr(vt[d] + 1, (int)s.size());
    xuli(ss);
    return 0;
}