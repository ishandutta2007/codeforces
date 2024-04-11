from collections import defaultdict as di
import sys
sys.setreqursiondepth = 1000000
MOD = int(1e9+7)
def modinvEuler(x,mod):
    # if mod is prime
    return pow(x, mod-2, mod)
    # otherwise exponent should be totient(mod)-1

k,pa,pb = [int(x) for x in input().split()]
Pa = (pa*modinvEuler(pa+pb,MOD))%MOD
Pb = (1-Pa)%MOD

Ea = modinvEuler(Pa,MOD)
Eb = modinvEuler(Pb,MOD)

Pbinv = modinvEuler(Pb,MOD)

mem = di()
def f(na,ns):
    #global k,Pa,Pb
    if ns>=k:
        return ns
    if na+ns>=k:
        total = ns
        total += na
        total += Pa*Pbinv
        total%= MOD
        return total
    if (na,ns) not in mem:
        mem[(na,ns)] = ( Pa*(f(na+1,ns))+Pb*(f(na,ns+na)) )%MOD

    return mem[(na,ns)]
print((f(1,0))%MOD)