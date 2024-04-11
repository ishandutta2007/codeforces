uses math;
var
  a,ll,rr,f,cur:array[0..20000] of longint; kol,n,m,i,j,l,r,k:longint;


begin

  readln(n,m);
  for i:=1 to n do
  begin
    read(kol); for j:=1 to kol do read(a[j]);
    fillchar(ll,sizeof(ll),0); fillchar(rr,sizeof(rr),0);
    for j:=1 to kol do ll[j]:=ll[j-1]+a[j]; for j:=kol downto 1 do rr[j]:=rr[j+1]+a[j];
    fillchar(cur,sizeof(cur),0);
    for l:=0 to kol do
      for r:=l+1 to kol+1 do
      begin
        cur[l+kol-r+1]:=max(cur[l+kol-r+1],ll[l]+rr[r]);
      end;
    for j:=m downto 0 do
      for k:=1 to kol do
      begin
        if j+k>m then break;
        f[j+k]:=max(f[j+k],f[j]+cur[k]);
      end;
    readln;
  end;
  writeln(f[m]);

end.