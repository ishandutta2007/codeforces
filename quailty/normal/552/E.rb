def max(a,b)
    return a>b ? a : b
end

s=gets
n=s.length
res=eval(s)
for i in -1..n-1 do
    if i==-1 || s[i]=='*'
        for j in i+1..n do
            if j==n || s[j]=='*'
                res=max(res,eval(s[0...i+1]+'('+s[i+1...j]+')'+s[j...n]))
            end
        end
    end
end
puts res