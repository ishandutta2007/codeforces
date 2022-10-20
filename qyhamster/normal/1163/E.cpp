 #include <iostream>
 #include <vector>
 #include <algorithm>
 using namespace std;
 const int maxn = 2e5 + 5;
 int a[maxn],t[maxn];
 int main()
 {
   int n;
   cin >> n;
   for(int i = 0; i < n; i++) cin >> a[i];
   sort(a,a+n);
   for(int i = 0; i < n; i++) t[i] = a[i];
   int x = a[n-1], cnt = 0;
   while(x)
   {
     x /= 2;
     cnt++;
   }
   vector<int> base;
   for(int l = cnt-1; l >= 0; l--)
   {
     while(n && t[n-1] >= (1<<(l+1))) n--;
     for(int i = 0; i < n; i++) a[i] = t[i];
     base.clear();
     bool ok = 1;
     for(int j = l; j >= 0; j--)
     {
       int target = -1;
       for(int i = 0; i < n; i++)
       {
         if((1<<j) & a[i])
         {
           target = i;
           break;
         }
       }
       if(target == -1)
       {
         ok = 0;
         break;
       }
       base.push_back(t[target]);
       int to_xor = a[target];
       for(int i = 0; i < n; i++)
       {
         if((1<<j) & a[i])
         {
           a[i] ^= to_xor;
         }
       }
     }
     if(ok) break;
     else base.clear();
     cnt--;
   }
   if(base.empty())
   {
     cout << 0 << endl << 0 << endl;
     exit(0);
   }
   vector<int> seq;
   seq.push_back(0);
   for(int j = 0; j < cnt; j++)
   {
     vector<int> tmp;
     for(int i = seq.size()-1; i >= 0; i--) tmp.push_back(seq[i]);
     for(int i = 0; i < seq.size(); i++) tmp.push_back(seq[i]^(1<<j));
     for(int i = tmp.size()-1; i >= 0; i--) tmp[i] ^= tmp[0];
     seq = tmp;
   }
   cout << cnt << endl;
   cout << 0;
   int num = 0;
   for(int i = 1; i < seq.size(); i++)
   {
     int x = seq[i] ^ seq[i-1];
     int cnt = 0;
     while(x > 1)
     {
       cnt++;
       x /= 2;
     }
     num ^= base[cnt];
     cout << " " << num;
   }
   cout << endl;
   return 0;
 }