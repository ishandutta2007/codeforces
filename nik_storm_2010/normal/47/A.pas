program storm;
var n:longint;
    priz:boolean;


procedure inputdata;
begin
 readln(n);
end;

procedure dix(chiclo:longint; var priz:boolean);
var l,r,d,nom:longint;
begin
 l:=1; r:=500;
 while r-l>1 do
  begin
  nom:=(l+r) div 2; d:=(nom*(nom+1)) div 2;
  if d>chiclo then r:=nom
              else l:=nom;
  end;
 if (r*(r+1)) div 2 = chiclo then begin priz:=true; exit; end;
 if (l*(l+1)) div 2 = chiclo then begin priz:=true; exit; end;
 priz:=false;
end;

procedure outputdata(priz:longint);
begin
 if priz=1 then writeln('YES')
           else writeln('NO');
end;

begin
 inputdata;
 dix(n,priz);
 if priz=true then outputdata(1)
              else outputdata(0);
end.