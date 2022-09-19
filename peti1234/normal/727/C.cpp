#include <bits/stdc++.h>

using namespace std;
int n, t[5002];
int kerd(int a, int b) {
    cout.flush() << "? " << a << " " << b << "\n";
    int x;
    cin >> x;
    return x;
}
int main()
{
    cin >> n;
    int egy_ketto=kerd(1, 2), egy_harom=kerd(1, 3), ketto_harom=kerd(2, 3);
    int osszeg=(egy_ketto+egy_harom+ketto_harom)/2;
    t[1]=osszeg-ketto_harom, t[2]=osszeg-egy_harom, t[3]=osszeg-egy_ketto;
    for (int i=4; i<=n; i++) {
        t[i]=kerd(1, i)-t[1];
    }
    cout << "! ";
    for (int i=1; i<=n; i++) {
        cout << t[i] << " ";
    }
    cout << "\n";
    return 0;
}
/*
Egyszeri interaktiv feladat. A kiiras formatumara kell figyelni.
cin.tie(0) sort TILOS beleirni, mert akkor elromlik az interakcio

Az elso 3 szamot egy kis trukkel ki lehet talalni.
Az elso erteket ismerve pedig ki lehet talalni minden mast is.

*/