uses math;
var
    a,f:array[1..2,1..1000,1..1000] of longint; path:array[1..1000,1..1000] of char;
      kol1,kol2,n,i,j,c,x,y:longint; s1,s2,s3:ansistring; havezero:boolean;


procedure razlog(tek,x,y:longint);
begin
  if tek=0 then
    begin
      a[1,x,y]:=500000; a[2,x,y]:=500000;
    end
      else
    begin
      while tek mod 2=0 do begin tek:=tek div 2; inc(a[1,x,y]); end;
      while tek mod 5=0 do begin tek:=tek div 5; inc(a[2,x,y]); end;
    end;
end;


procedure findanswer(tek:longint; var kol:longint; var s:ansistring);
var i,j:longint;
begin
  f[1,1,1]:=a[1,1,1]; f[2,1,1]:=a[2,1,1];
  for i:=2 to n do
    begin
      f[1,1,i]:=a[1,1,i]+f[1,1,i-1]; f[2,1,i]:=a[2,1,i]+f[2,1,i-1]; path[1,i]:='R';
      f[1,i,1]:=a[1,i,1]+f[1,i-1,1]; f[2,i,1]:=a[2,i,1]+f[2,i-1,1]; path[i,1]:='D';
    end;
  for i:=2 to n do
    for j:=2 to n do
    begin
      if (f[tek,i-1,j]<f[tek,i,j-1]) or ((f[tek,i-1,j]=f[tek,i,j-1]) and (f[3-tek,i-1,j]<f[3-tek,i,j-1])) then
      begin
        f[1,i,j]:=f[1,i-1,j]+a[1,i,j]; f[2,i,j]:=f[2,i-1,j]+a[2,i,j]; path[i,j]:='D';
      end
        else
      begin
        f[1,i,j]:=f[1,i,j-1]+a[1,i,j]; f[2,i,j]:=f[2,i,j-1]+a[2,i,j]; path[i,j]:='R';
      end;
    end;
  kol:=min(f[1,n,n],f[2,n,n]);
  i:=n; j:=n;
  while i+j<>2 do
    begin
      s:=path[i,j]+s;
      if path[i,j]='D' then dec(i) else dec(j);
    end;
end;


begin

  readln(n); havezero:=false;
  for i:=1 to n do
    begin
      for j:=1 to n do
        begin
          read(c); razlog(c,i,j);
          if c=0 then begin havezero:=true; x:=i; y:=j; end;
        end;
      readln;
    end;
  findanswer(1,kol1,s1); findanswer(2,kol2,s2);
  if (min(kol1,kol2)>1) and (havezero=true) then
    begin
      a[1,x,y]:=-maxlongint; a[2,x,y]:=-maxlongint;
      findanswer(1,kol1,s3); writeln(1); writeln(s3);
    end
      else
    begin
      if kol1<kol2 then
        begin
          writeln(kol1); writeln(s1);
        end
          else
        begin
          writeln(kol2); writeln(s2);
        end;
    end;

end.