#include <bits/stdc++.h>

using namespace std;
int t[6];
int main()
{
    for (int i=1; i<6; i++){
        cin >> t[i];
    }
    int osszeg=0;
    for (int i=1; i<6; i++){
        osszeg=osszeg+t[i];
    }
    int elso, masodik, harmadik, negyedik, otodik;
    elso=0;
    masodik=0;
    harmadik=0;
    negyedik=0;
    otodik=0;
    for (int i=1; i<6; i++){
        if (t[i]==t[1]){
            elso=elso+t[1];
        }
        if (t[i]==t[2]){
            masodik=masodik+t[2];
        }
        if (t[i]==t[3]){
            harmadik=harmadik+t[3];
        }
        if (t[i]==t[4]){
            negyedik=negyedik+t[4];
        }
        if (t[i]==t[5]){
            otodik=otodik+t[5];
        }

    }
    if (elso>t[1]*3){
        elso=t[1]*3;
    }
    if (masodik>t[2]*3){
        masodik=t[2]*3;
    }
    if (harmadik>t[3]*3){
        harmadik=t[3]*3;
    }
    if (negyedik>t[4]*3){
        negyedik=t[4]*3;
    }
    if (otodik>t[5]*3){
        otodik=t[5]*3;
    }
    int legnagyobb=0;
    if (elso>t[1] && elso>legnagyobb){
        legnagyobb=elso;
    }
    if (masodik>t[2] && masodik>legnagyobb){
        legnagyobb=masodik;
    }
    if (harmadik>t[3] && harmadik>legnagyobb){
        legnagyobb=harmadik;
    }
    if (negyedik>t[4] && negyedik>legnagyobb){
        legnagyobb=negyedik;
    }
    if (otodik>t[5] && otodik>legnagyobb){
        legnagyobb=otodik;
    }
    cout << osszeg-legnagyobb << endl;

    return 0;
}