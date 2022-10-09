#include <bits/stdc++.h>

using namespace std;

int kol;
vector <string> sn;
string st,name;


int main() {
    cin >> st;

    int ln=st.length();


    sn.clear();
    int i=0;
    kol=0;
    while (i<ln) {

        if (st[i]>='A' && st[i]<='Z') {
            name="";
            while (st[i]>='A' && st[i]<='Z') {

                name+=st[i];
                i++;
            }
            sn.push_back(name);
            for (int j=0; j<sn.size()-1; j++)
                if (name==sn[j]) kol++;
        } else
        if (st[i]=='.'){
            sn.pop_back();
            i++;
        } else {
            i++;
        }

    }

    cout << kol;

    return 0;

}