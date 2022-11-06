#include <bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%d", &x)
#define slld(x) scanf("%lld", &x)
#define all(x) x.begin(), x.end()
#define For(i, st, en) for(ll i=st; i<en; i++)
#define tr(x) for(auto it=x.begin(); it!=x.end(); it++)
#define fast std::ios::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define ll long long
#define int long long
#define mp make_pair
#define F first
#define S second
typedef pair<int, int> pii;

map<int, string> m;
map<string, int> m1;
map<string, string> ans;
int ct = 0;

void play(){
    string s;
    getline(cin, s);
    For(j, 1, ct+1){
        getline(cin, s);
        string sal = "";
        int i = 9;
        while(s[i]!='}'){
            sal.pb(s[i]);
            i++;
        }
        m1[sal] = j;
        int remlength = s.length()-i-1;
        string ss = s.substr(i+1, remlength);
        ans[sal] = ss;
    }
}

signed main(){
    fast
    #ifndef ONLINE_JUDGE
        freopen("/home/swapnil/Desktop/c++/input.txt","r",stdin);
        freopen("/home/swapnil/Desktop/c++/output.txt","w",stdout);
    #endif
    string s;
    while(cin>>s){
        int z = (int)s[0];
        if(z!=92){
            continue;
        }
        string s1 = s.substr(1, 5);
        if(s1=="cite{"){
            ct++;
            string sal = "";
            int i = 6;
            while(s[i]!='}'){
                sal.pb(s[i]);
                i++;
            }
            m[ct]=sal;
            continue;
        }

        s1 = s.substr(1, 22);
        if(s1=="begin{thebibliography}"){
            play();
            break;
        }
    }

    bool flag = true;

    tr(m){
        string ch = it->S;
        int v = it->F;
        if(m1[ch]!=v){
            flag = false;
            break;
        }
    }

    if(flag){
        cout<<"Correct";
        return 0;
    }

    cout<<"Incorrect"<<endl;
    cout<<"\\begin{thebibliography}{99}"<<endl;
    tr(m){
        string ch = it->S;
        cout<<"\\bibitem{"<<ch<<"}"<<ans[ch]<<endl;
    }
    cout<<"\\end{thebibliography}";

    return 0;
}