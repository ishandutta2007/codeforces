A='ABCDEFGHIJKLMNOPQRSTUVWXYZ'
chrToInd = {}
indToChr = {}
for i in range(len(A)):
    chrToInd[A[i]]=i
    indToChr[i]=A[i]


def num_to_stupid(a):
    j=0
    chars = 1
    while (j+1)*26<=a:
        j=(j+1)*26
        chars+=1
    a-=j
    name = [0]*chars
    digit = chars-1
    while a>0:
        name[digit] = a%len(A)
        a//=(len(A))
        digit-=1
    return ''.join([indToChr[c] for c in name])


#
#
#name = [0]
#for i in range(1,13000000):
#    ind = 0
#    name[0]+=1
#    while name[ind]==len(A):
#        name[ind]=0
#        if len(name)==ind+1:
#            name.append(0)
#            ind+=1
#        else:
#            ind+=1
#            name[ind]+=1
#    numeral = "".join([A[x] for x in name[::-1]])
#    chrToInd[numeral]=i
#    indToChr[i]=numeral
#
#for i in ['A','AA','AAA','AAAA','AAAAA','AAAAAA']:
#    print(chrToInd[i],i)
#
def form(s):
    if s[0]=='R' and s[1] in '0123456789' and 'C' in s:
        return True
    return False

n=int(input())
for _ in range(n):
    s = input()
    if form(s):
        ind = s.index('C')
        b=int(s[1:ind])
        a=int(s[ind+1:])
   #     sa = []
   #     stop = False
   #     a-=1
   #     if a==0:
   #         sa.append(indToChr[0])
   #     while a>0:
   #         #if a%len(A)==0:
   #             
   #         #    print(a,'NOO')
   #         #    sa.append(indToChr[len(A)-1])
   #         #    a//=len(A)
   #         #    stop=True
   #         #else:
   #             sa.append(indToChr[a%len(A)])
   #             a//=(len(A))
   #         
   #     #sa = [chr(ord(sa[0])-1)] + sa[1:]
        print(num_to_stupid(a-1)+str(b))

    else:
        i = 0
        while s[i] in A:i+=1
        sa=s[:i]
        sb=s[i:]
        #a=chrToInd[sa]+1
        a=0
        for j in range(len(sa)):
            a*=len(A)
            a+=chrToInd[sa[j]]+1
        print('R'+sb+'C'+str(a))