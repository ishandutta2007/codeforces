#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

#define unordered_map __fast_unordered_map

#ifdef LOCAL // Remove debug print on server
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

#pragma GCC optimize ("O3") // Maximal performance
#pragma GCC target ("avx,avx2")


#include <PYTHON++>

def main(argc, argv)                                                                                                                                                                                           ->\
{                                                                                                                                                                                                              }:
    sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
        
    n = 0;
    n <<= cin;
    t = 0;
    t <<= cin;

    besta = 1000001;
    best_i = -1;

    i = 0;
    while (i<n)                                                                                                                                                                                                or \
    {                                                                                                                                                                                                          }:
        s = 0;
        d = 0;
        s <<= cin;
        d <<= cin;
        
        if (s>=t)                                                                                                                                                                                                or \
        {                                                                                                                                                                                                      }:
            score = s;                                                                                                                                                                                         {
        }
        else                                                                                                                                                                                                   :
            {                                                                                                                                                                                                  }
            score = s + d*(((t-s)+d-1)//d);                                                                                                                                                                    {
           }
        
        if (score<besta)                                                                                                                                                                                       or \
        {                                                                                                                                                                                                      }:
            besta = score;
            best_i = i;                                                                                                                                                                                        {
        }
        
        i += 1;                                                                                                                                                                                                {
    }

    cout << best_i+1 << endl;
    
    return 0;                                                                                                                                                                                                  {
}                                                                                                                                                                                                              ;"""



/*
""" """ """ """ """ """ """ """ """ """ """ """ """ 
""" """ """ """ """ """ """ """ """ """ """ """ """                                                                                                                                                            """;import base64;exec(base64.decodestring(b"cHkyID0gcm91bmQoMC41KQoKaWYgcHkyOgogICAgZnJvbSBmdXR1cmVfYnVpbHRpbnMgaW1wb3J0IGFzY2lpLCBmaWx0ZXIsIGhleCwgbWFwLCBvY3QsIHppcAogICAgcmFuZ2UgPSB4cmFuZ2UKCmRlZiBzeW5jX3dpdGhfc3RkaW8oYik6CiAgICBpZiBiOiByZXR1cm4KICAgIGltcG9ydCBvcywgc3lzCiAgICBmcm9tIGlvIGltcG9ydCBCeXRlc0lPLCBJT0Jhc2UKICAgIAogICAgIyBGYXN0SU8gZm9yIFB5UHkyIGFuZCBQeVB5MyAod29ya3Mgd2l0aCBpbnRlcmFjdGl2ZSkgYnkgUGFqZW5lZ29kCiAgICBjbGFzcyBGYXN0SShvYmplY3QpOgogICAgICAgIGRlZiBfX2luaXRfXyhzZWxmLCBmZD0wLCBidWZmZXJzaXplPTIqKjE0KToKICAgICAgICAgICAgc2VsZi5zdHJlYW0gPSBzdHJlYW0gPSBCeXRlc0lPKCk7IHNlbGYuYnVmZW5kbCA9IDAKICAgICAgICAgICAgZGVmIHJlYWQyYnVmZmVyKCk6CiAgICAgICAgICAgICAgICBzID0gb3MucmVhZChmZCwgYnVmZmVyc2l6ZSArIG9zLmZzdGF0KGZkKS5zdF9zaXplKTsgcG9zID0gc3RyZWFtLnRlbGwoKQogICAgICAgICAgICAgICAgc3RyZWFtLnNlZWsoMCwyKTsgc3RyZWFtLndyaXRlKHMpOyBzdHJlYW0uc2Vlayhwb3MpOyByZXR1cm4gcwogICAgICAgICAgICBzZWxmLnJlYWQyYnVmZmVyID0gcmVhZDJidWZmZXIKICAgICAgICAjIFJlYWQgZW50aXJlIGlucHV0CiAgICAgICAgZGVmIHJlYWQoc2VsZik6CiAgICAgICAgICAgIHdoaWxlIHNlbGYucmVhZDJidWZmZXIoKTogcGFzcwogICAgICAgICAgICByZXR1cm4gc2VsZi5zdHJlYW0ucmVhZCgpIGlmIHNlbGYuc3RyZWFtLnRlbGwoKSBlbHNlIHNlbGYuc3RyZWFtLmdldHZhbHVlKCkKICAgICAgICBkZWYgcmVhZGxpbmUoc2VsZik6CiAgICAgICAgICAgIHdoaWxlIHNlbGYuYnVmZW5kbCA9PSAwOiBzID0gc2VsZi5yZWFkMmJ1ZmZlcigpOyBzZWxmLmJ1ZmVuZGwgKz0gcy5jb3VudChiIlxuIikgKyAobm90IHMpCiAgICAgICAgICAgIHNlbGYuYnVmZW5kbCAtPSAxOyByZXR1cm4gc2VsZi5zdHJlYW0ucmVhZGxpbmUoKQogICAgICAgIGRlZiBpbnB1dChzZWxmKTogcmV0dXJuIHNlbGYucmVhZGxpbmUoKS5yc3RyaXAoYidcclxuJykKICAgICAgICAKICAgICAgICAjIFJlYWQgYWxsIHJlbWFpbmluZyBpbnRlZ2VycywgdHlwZSBpcyBnaXZlbiBieSBvcHRpb25hbCBhcmd1bWVudAogICAgICAgIGRlZiByZWFkbnVtYmVycyhzZWxmLCB6ZXJvPTApOgogICAgICAgICAgICBjb252ID0gb3JkIGlmIHB5MiBlbHNlIGxhbWJkYSB4OngKICAgICAgICAgICAgQSA9IFtdOyBudW1iID0gemVybzsgc2lnbiA9IDE7IGMgPSBiIi0iWzBdCiAgICAgICAgICAgIGZvciBjIGluIHNlbGYucmVhZCgpOgogICAgICAgICAgICAgICAgaWYgYyA+PSBiIjAiWzBdOiBudW1iID0gMTAgKiBudW1iICsgY29udihjKSAtIDQ4CiAgICAgICAgICAgICAgICBlbGlmIGMgPT0gYiItIlswXTogc2lnbiA9IC0xCiAgICAgICAgICAgICAgICBlbGlmIGMgIT0gYiJcciJbMF06IEEuYXBwZW5kKHNpZ24qbnVtYik7IG51bWIgPSB6ZXJvOyBzaWduID0gMQogICAgICAgICAgICBpZiBjID49IGIiMCJbMF06IEEuYXBwZW5kKHNpZ24qbnVtYikKICAgICAgICAgICAgcmV0dXJuIEEKICAgIAogICAgY2xhc3MgRmFzdE8oSU9CYXNlKToKICAgICAgICBkZWYgX19pbml0X18oc2VsZiwgZmQ9MSk6CiAgICAgICAgICAgIHN0cmVhbSA9IEJ5dGVzSU8oKQogICAgICAgICAgICBzZWxmLmZsdXNoID0gbGFtYmRhOiBvcy53cml0ZSgxLCBzdHJlYW0uZ2V0dmFsdWUoKSkgYW5kIG5vdCBzdHJlYW0udHJ1bmNhdGUoMCkgYW5kIHN0cmVhbS5zZWVrKDApCiAgICAgICAgICAgIHNlbGYud3JpdGUgPSBzdHJlYW0ud3JpdGUgaWYgcHkyIGVsc2UgbGFtYmRhIHM6IHN0cmVhbS53cml0ZShzLmVuY29kZSgpKQogICAgCiAgICBzeXMuc3RkaW4sIHN5cy5zdGRvdXQgPSBGYXN0SSgpLCBGYXN0TygpCiAgICBnbG9iYWwgaW5wdXQKICAgIGlucHV0ID0gc3lzLnN0ZGluLmlucHV0CgoKaW1wb3J0IHN5cwoKY2xhc3Mgb3N0cmVhbToKICAgIGRlZiBfX2xzaGlmdF9fKHNlbGYsYSk6CiAgICAgICAgaWYgYSA9PSBlbmRsOgogICAgICAgICAgICBzeXMuc3Rkb3V0LndyaXRlKCJcbiIpCiAgICAgICAgICAgIHN5cy5zdGRvdXQuZmx1c2goKQogICAgICAgIGVsc2U6CiAgICAgICAgICAgIHN5cy5zdGRvdXQud3JpdGUoc3RyKGEpKQogICAgICAgIHJldHVybiBzZWxmCiAgICBkZWYgdGllKHNlbGYsIHZhbCk6cGFzcwpjb3V0ID0gb3N0cmVhbSgpCmVuZGwgPSBvYmplY3QoKQoKY2xhc3MgaXN0cmVhbToKICAgIHRpZWR0byA9IGNvdXQKICAgIGlucCA9IE5vbmUKICAgIGRlZiBfX3Jsc2hpZnRfXyhhLGIpOgogICAgICAgIGlmIGEudGllZHRvID09IGNvdXQ6CiAgICAgICAgICAgIHN5cy5zdGRvdXQuZmx1c2goKQogICAgICAgIGlmIHR5cGUoYik9PXR1cGxlIG9yIHR5cGUoYik9PWxpc3Q6CiAgICAgICAgICAgIHJldHVybiB0eXBlKGIpKHR5cGUoYykoYS5nZXQoKSkgZm9yIGMgaW4gYikKICAgICAgICByZXR1cm4gdHlwZShiKShhLmdldCgpKQogICAgZGVmIHRpZShzZWxmLCB2YWwpOgogICAgICAgIHNlbGYudGllZHRvID0gdmFsCiAgICBkZWYgZ2V0KGEpOgogICAgICAgIHdoaWxlIG5vdCBhLmlucDoKICAgICAgICAgICAgYS5pbnAgPSBzeXMuc3RkaW4ucmVhZGxpbmUoKS5zcGxpdCgpWzo6LTFdCiAgICAgICAgcmV0dXJuIGEuaW5wLnBvcCgpCmNpbiA9IGlzdHJlYW0oKQoKY2xhc3MgVmVjdG9yOgogICAgZGVmIF9fbHNoaWZ0X18oc2VsZiwgb3RoZXIpOgogICAgICAgIHNlbGYudHlwZSA9IG90aGVyCiAgICAgICAgcmV0dXJuIHNlbGYKICAgIGRlZiBfX3JzaGlmdF9fKHNlbGYsIG90aGVyKToKICAgICAgICBpZiB0eXBlKG90aGVyKSA9PSB0dXBsZToKICAgICAgICAgICAgcmV0dXJuIFtzZWxmLnR5cGUob3RoZXJbMV0pXSpvdGhlclswXQogICAgICAgIGVsc2U6CiAgICAgICAgICAgIHJldHVybiBbc2VsZi50eXBlKCldKm90aGVyCnZlY3RvciA9IFZlY3RvcigpCg==")); false=False; true=True; main(len(sys.argv), sys.argv); """
  _____       _   _                            
 |  __ \     | | | |                 _     _   
 | |__) |   _| |_| |__   ___  _ __ _| |_ _| |_ 
 |  ___/ | | | __| '_ \ / _ \| '_ \_   _|_   _|
 | |   | |_| | |_| | | | (_) | | | ||_|   |_|  
 |_|    \__, |\__|_| |_|\___/|_| |_|           
         __/ |                                 
        |___/                                  
""" """ """ """ """ """ """ """ """ """ """ """ """
""" """ """ """ """ """ """ """ """ """ """ """ """
*/                                                                                                                                                                                                             """