
import Control.Monad
import Control.Applicative
import Data.List
import qualified Data.Map as Map
import qualified Data.Set as Set
import Data.Array

readInt :: IO Integer
readInt = read <$> getLine
readIntList :: IO [Integer]
readIntList = fmap read . words <$> getLine
readIntArray :: Integer -> IO (Array Integer Integer)
readIntArray n = listArray (0, n-1) <$> readIntList
readSortedIntArray :: Integer -> IO (Array Integer Integer)
readSortedIntArray n = listArray (0, n-1) . sort <$> readIntList

main :: IO ()
main = do
  [c, d] <- readIntList
  [n, m] <- readIntList
  [k] <- readIntList
  putStrLn . show $ minimum $ flip fmap [0..1000] $ \i -> i * c + (max 0 $ n * m - i * n - k) * d