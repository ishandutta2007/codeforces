program storm;
var s:string;
    d,k,i,kof,nom:longint;
    used:array[1..30] of boolean;
    priz:boolean;


procedure inputdata;
begin
 readln(k);
 readln(s);
end;

procedure prov(var priz:boolean);
var i:longint;
begin
 priz:=true;
 for i:=1 to (d div 2) do
  if (s[i]<>s[d-i+1]) and (ord(s[i])<>63) and (ord(s[d-i+1])<>63)
        then begin priz:=false; exit; end;
end;

procedure outputdata(priz:longint);
begin
 if priz=1 then writeln(s)
           else writeln('IMPOSSIBLE');
end;

procedure poisk(var nom:longint);
var i:longint;
begin
 nom:=0;
 for i:=k downto 1 do
  if used[i] = false then begin nom:=i; exit; end;
end;

begin
 inputdata;
 d:=length(s);
 if (k*2)-1>d then begin outputdata(0); halt; end;
 for i:=1 to d do
    if ord(s[i])<>63 then used[ord(s[i])-96]:=true;
 prov(priz);
 if priz=false then begin outputdata(0); halt; end; kof:=(d div 2)+(d mod 2);
 for i:=kof downto 1 do
  if (ord(s[i])=63) or (ord(s[d-i+1])=63) then
       begin
       if (ord(s[i])=63) and (ord(s[d-i+1])=63)
          then
            begin
             poisk(nom);
             if nom=0 then begin s[i]:='a'; s[d-i+1]:='a'; end
                      else begin s[i]:=chr(nom+96); s[d-i+1]:=chr(nom+96); used[nom]:=true; end;
            end;
       if (ord(s[i])=63)     then s[i]:=s[d-i+1];
       if (ord(s[d-i+1])=63) then s[d-i+1]:=s[i];
       end;
 for i:=1 to k do
  if used[i]<>true then begin outputdata(0); halt; end;
 outputdata(1);
end.