var
 s : ansistring; p1,p2,p3,p4 : ansistring;
  aabb,abab,abba,aaaa : boolean;
   d,i,n,k : longint; nom:longint;


procedure pre(s:ansistring; var prefix:ansistring);
var i,tek:longint;
 begin
  tek:=k; i:=length(s);
   while tek<>0 do
    begin
     prefix:=s[i]+prefix;
      if (s[i]='a') or (s[i]='e') or (s[i]='i') or (s[i]='o') or (s[i]='u') then dec(tek);
       if tek=0 then exit;
      dec(i);
     if i=0 then begin str(nom,prefix); inc(nom); exit; end;
    end;
 end;


begin

  readln(n,k); nom:=0;
   aabb:=true; abab:=true; abba:=true; aaaa:=true;
    for i:=1 to n do
     begin
      readln(s); pre(s,p1);
       readln(s); pre(s,p2);
       readln(s); pre(s,p3);
      readln(s); pre(s,p4);

      if (p1=p2) and (p3=p4) and (aabb=true) then aabb:=true else aabb:=false;
       if (p1=p3) and (p2=p4) and (abab=true) then abab:=true else abab:=false;
       if (p1=p4) and (p2=p3) and (abba=true) then abba:=true else abba:=false;
      if (p1=p2) and (p2=p3) and (p3=p4) and (aaaa=true) then aaaa:=true else aaaa:=false;
     end;
     if aaaa=true then writeln('aaaa') else
    if aabb=true then writeln('aabb') else
   if abab=true then writeln('abab') else
  if abba=true then writeln('abba') else writeln('NO');

end.