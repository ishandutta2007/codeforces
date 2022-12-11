#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main()
{
    string labs,fir;
    cin >> labs >> fir;
    int b = -1;
    for(int i = 0;i<fir.size();i++){
        if(fir[i] == '*'){
            b = i;
        }
    }
    int m;
    cin >> m;
    string st;
    int att;
    bool t;
    int y;
    int pos;
    for(int x = 0;x<m;x++){
        cin >> st;
        if(fir.size()>st.size()+1){
            cout << "NO\n";
        }
        else{
            if(b == -1){
                if(fir.size() != st.size()){
                    cout << "NO\n";
                }
                else{
                    t = true;
                    for(int i = 0;i<st.size();i++){
                        if(fir[i] == '?'){
                            if(labs.find(st[i]) == -1){
                                t = false;
                            }
                        }
                        else{
                            if(fir[i] != st[i]){
                                t = false;
                            }
                        }
                    }
                    if(t == true){
                        cout << "YES\n";
                    }
                    else{
                        cout << "NO\n";
                    }
                }
            }
            else{
                t = true;
                att = st.size() - fir.size();
                att++;
                y = b+1;
                pos = b;
                for(int i = 0;i<b;i++){
                    if(fir[i] == '?'){
                        if(labs.find(st[i]) == -1){
                            t = false;
                        }
                    }
                    else{
                        if(fir[i] != st[i]){
                            t = false;
                        }
                    }
                }
                for(int i = 0;i<att && pos < st.size();i++){
                    if(labs.find(st[pos]) != -1){
                        t = false;
                    }
                    pos++;
                }
                while(pos<st.size()){
                    if(fir[y] == '?'){
                        if(labs.find(st[pos]) == -1){
                            t = false;
                        }
                    }
                    else{
                        if(fir[y] != st[pos]){
                            t = false;
                        }
                    }
                    y++;
                    pos++;
                }

                if(t == true){
                    cout << "YES\n";
                }
                else{
                    cout << "NO\n";
                }
            }
        }
    }
    return 0;
}