uses math;
var
    a:array[1..1000,1..1000] of char; cv,f:array[1..2,0..1000] of longint;
      color,kolw,kolb,tek,i,j,n,m,x,y:longint;


begin

  readln(n,m,x,y);
  for i:=1 to n do
    begin
      for j:=1 to m do read(a[i,j]);
      readln;
    end;
  for j:=1 to m do
    begin
      kolw:=0; kolb:=0;
      for i:=1 to n do
        if a[i,j]='.' then inc(kolw) else inc(kolb);
      cv[1,j]:=cv[1,j-1]+kolw; cv[2,j]:=cv[2,j-1]+kolb;
    end;
  for tek:=1 to m do
    begin
      for color:=1 to 2 do
        begin
          f[color,tek]:=maxlongint;
          for i:=x to y do
            if tek-i>=0 then
            begin
              if f[3-color,tek-i]<>maxlongint then
              begin
                f[color,tek]:=min(f[color,tek],f[3-color,tek-i]+cv[3-color,tek]-cv[3-color,tek-i]);
              end;
            end;
        end;
    end;
  writeln(min(f[1,m],f[2,m]));

end.