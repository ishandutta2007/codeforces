uses math;
 var
     i,n,m,k,a1,b1,c1,x,y,w:longint;


begin

  a1:=0; b1:=0; c1:=maxlongint;
  read(n); for i:=1 to n do begin read(w); a1:=max(a1,w); end; readln;
  read(m); for i:=1 to m do begin read(w); b1:=max(b1,w); end; readln;
  read(k); for i:=1 to k do begin read(w); c1:=min(c1,w); end; readln;
  read(x,y); writeln(a1*sqrt((y*b1)/(y*b1+x*c1)):0:9);

end.