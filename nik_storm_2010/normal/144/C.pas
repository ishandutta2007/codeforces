var
 a:array[97..122] of longint;
  b:array[97..122] of longint;
   lengs,lengp,i,q,answer:longint;
    s,p:ansistring; priz:boolean;


procedure inputdata;
var i:longint;
 begin
  readln(s); lengs:=length(s);
   readln(p);
    lengp:=length(p);
     for i:=1 to lengp do inc(b[ord(p[i])]);
 end;


procedure proverka(var priz:boolean);
var i,need:longint;
 begin
  priz:=false;
   need:=0;
    for i:=97 to 122 do
     if a[i]>b[i] then exit else
      if a[i]<b[i] then need:=need+b[i]-a[i];
  if need=q then priz:=true;
 end;


begin

  inputdata;
   answer:=0;
    if lengs>=lengp
     then
      begin
       q:=0;
        for i:=1 to lengp do
         if s[i]='?' then inc(q) else inc(a[ord(s[i])]);
        proverka(priz);
       if priz = true then inc(answer);
        for i:=1 to lengs-lengp do
         begin
          if s[i]='?' then dec(q) else dec(a[ord(s[i])]);
           if s[i+lengp]='?' then inc(q) else inc(a[ord(s[i+lengp])]);
           proverka(priz);
          if priz=true then inc(answer);
         end;
      end
     else
      begin
      end;
  writeln(answer);

end.