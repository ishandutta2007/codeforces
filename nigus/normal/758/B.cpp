#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll mod = 1000000007ll;
ll n,m;

string s;
string s2 = "RBYG";
string s1;

ll ANS[4] = {0};

bool test(){
    bool yes = 1;
    for(ll c1 = 3; c1 < n; c1++){
        char take = 'e';
        ll itake = 0;
        for(ll c2 = 0; c2 < 4; c2++){
            if(s2[c2] != s1[c1-1] &&  s2[c2] != s1[c1-2] && s2[c2] != s1[c1-3]){
                take = s2[c2];
                itake = c2;
                break;
            }
        }
        if(take == 'e' || (s1[c1] != '!' && s1[c1] != take)){
            yes = 0;
        }
        if(s1[c1] == '!'){
            ANS[itake]++;
        }
        s1[c1] = take;
    }
    return yes;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll c1,c2,c3,c4,c5;
    cin >> s;
    n = s.length();
    vector<ll> A;
    for(c1 = 0; c1 < n; c1++){
        if(s[c1] == 'R')A.push_back(0);
        if(s[c1] == 'B')A.push_back(1);
        if(s[c1] == 'Y')A.push_back(2);
        if(s[c1] == 'G')A.push_back(3);
        if(s[c1] == '!')A.push_back(-1);
    }

    string S[24];

    for(c1 = 0; c1 < 4; c1++){

        string base = "";
        for(c2 = 0; c2 < 4; c2++){
            if(c1 != c2){
                base += s2[c2];
            }
        }

        for(c2 = 0; c2 < 6; c2++){
            S[c1*6+c2] = base;
            next_permutation(base.begin() , base.end());
        }
    }

    for(c1 = 0; c1 < 24; c1++){
        s1 = s;
        bool go = 1;
        for(c2 = 0; c2 < 3; c2++){
            if(s[c2] != '!' && S[c1][c2] != s[c2])go = 0;
        }
        if(go == 1){
            ANS[0] = 0;
            ANS[1] = 0;
            ANS[2] = 0;
            ANS[3] = 0;
            for(c2 = 0; c2 < 3; c2++){
                s1[c2] = S[c1][c2];
                if(s[c2] == '!'){
                    if(s1[c2] == 'R')ANS[0]++;
                    if(s1[c2] == 'B')ANS[1]++;
                    if(s1[c2] == 'Y')ANS[2]++;
                    if(s1[c2] == 'G')ANS[3]++;
                }
            }
          //  cout << S[c1] << " ";
            if(test())break;
        }
    }

    for(c1 = 0; c1 < 4; c1++){
        cout << ANS[c1] << " ";
    }


    return 0;
}