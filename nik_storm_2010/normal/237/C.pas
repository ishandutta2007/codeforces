var
    prost:array[1..5000000] of boolean; f:array[1..5000000] of longint;
      tek,a,b,i:int64; nom,l,r,m,k:longint;


function maybe(c:longint):boolean;
var i:longint;
begin
  for i:=a to b-c+1 do
    if f[i]-f[i+c]<k then begin maybe:=false; exit; end;
  maybe:=true;
end;


begin

  readln(a,b,k); prost[1]:=true; i:=2;
  while i<=b do
    begin
      if prost[i]=false then
      begin
        tek:=i*i;
        while tek<=b do
          begin
            prost[tek]:=true;
            tek:=tek+i;
          end;
      end;
      inc(i);
    end;
  for nom:=b downto a do
    if prost[nom]=false then f[nom]:=f[nom+1]+1 else f[nom]:=f[nom+1];
  l:=1; r:=b-a+1;
  while r-l>1 do
    begin
      m:=(r+l) div 2;
      if maybe(m) then r:=m else l:=m;
    end;
  if maybe(l)=true then
    begin
      writeln(l);
      halt;
    end
      else
    begin
      if maybe(r)=true then
        begin
          writeln(r);
          halt;
        end;
    end;
  writeln(-1);

end.